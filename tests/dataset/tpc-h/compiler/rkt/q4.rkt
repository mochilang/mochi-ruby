#lang racket
(require json)
(define (_date_number s)
  (let ([parts (string-split s "-")])
    (if (= (length parts) 3)
        (+ (* (string->number (list-ref parts 0)) 10000)
           (* (string->number (list-ref parts 1)) 100)
           (string->number (list-ref parts 2)))
        #f)))

(define (_to_string v) (format "~a" v))

(define (_lt a b)
  (cond
    [(and (number? a) (number? b)) (< a b)]
    [(and (string? a) (string? b))
     (let ([da (_date_number a)]
           [db (_date_number b)])
       (if (and da db)
           (< da db)
           (string<? a b)))]
    [(and (list? a) (list? b))
     (cond [(null? a) (not (null? b))]
           [(null? b) #f]
           [else (let ([ka (car a)] [kb (car b)])
                   (if (equal? ka kb)
                       (_lt (cdr a) (cdr b))
                       (_lt ka kb)))])]
    [else (string<? (_to_string a) (_to_string b))]))

(define (_gt a b) (_lt b a))
(define (_le a b) (or (_lt a b) (equal? a b)))
(define (_ge a b) (or (_gt a b) (equal? a b)))

(define (_min v)
  (let* ([lst (cond [(and (hash? v) (hash-has-key? v 'items)) (hash-ref v 'items)]
                    [(list? v) v]
                    [else '()])]
         [m 0])
    (when (not (null? lst))
      (set! m (car lst))
      (for ([n (cdr lst)])
        (when (_lt n m) (set! m n))))
    m))

(define (_max v)
  (let* ([lst (cond [(and (hash? v) (hash-has-key? v 'items)) (hash-ref v 'items)]
                    [(list? v) v]
                    [else '()])]
         [m 0])
    (when (not (null? lst))
      (set! m (car lst))
      (for ([n (cdr lst)])
        (when (_gt n m) (set! m n))))
    m))

(define orders (list (hash 'o_orderkey 1 'o_orderdate "1993-07-01" 'o_orderpriority "1-URGENT") (hash 'o_orderkey 2 'o_orderdate "1993-07-15" 'o_orderpriority "2-HIGH") (hash 'o_orderkey 3 'o_orderdate "1993-08-01" 'o_orderpriority "3-NORMAL")))
(define lineitem (list (hash 'l_orderkey 1 'l_commitdate "1993-07-10" 'l_receiptdate "1993-07-12") (hash 'l_orderkey 1 'l_commitdate "1993-07-12" 'l_receiptdate "1993-07-10") (hash 'l_orderkey 2 'l_commitdate "1993-07-20" 'l_receiptdate "1993-07-25") (hash 'l_orderkey 3 'l_commitdate "1993-08-02" 'l_receiptdate "1993-08-01") (hash 'l_orderkey 3 'l_commitdate "1993-08-05" 'l_receiptdate "1993-08-10")))
(define start_date "1993-07-01")
(define end_date "1993-08-01")
(define date_filtered_orders (for*/list ([o orders] #:when (and (and (string>=? (hash-ref o 'o_orderdate) start_date) (string<? (hash-ref o 'o_orderdate) end_date)))) o))
(define late_orders (for*/list ([o date_filtered_orders] #:when (and (not (null? (for*/list ([l lineitem] #:when (and (and (equal? (hash-ref l 'l_orderkey) (hash-ref o 'o_orderkey)) (_lt (hash-ref l 'l_commitdate) (hash-ref l 'l_receiptdate))))) l))))) o))
(define result (let ([groups (make-hash)])
  (for* ([o late_orders]) (let* ([key (hash-ref o 'o_orderpriority)] [bucket (hash-ref groups key '())]) (hash-set! groups key (cons o bucket))))
  (define _groups (for/list ([k (hash-keys groups)]) (hash 'key k 'items (hash-ref groups k))))
  (set! _groups (sort _groups (lambda (a b) (cond [(string? (let ([g a]) (hash-ref g 'key))) (string>? (let ([g a]) (hash-ref g 'key)) (let ([g b]) (hash-ref g 'key)))] [(string? (let ([g b]) (hash-ref g 'key))) (string>? (let ([g a]) (hash-ref g 'key)) (let ([g b]) (hash-ref g 'key)))] [else (> (let ([g a]) (hash-ref g 'key)) (let ([g b]) (hash-ref g 'key)))]))))
  (for/list ([g _groups]) (hash 'o_orderpriority (hash-ref g 'key) 'order_count (length (hash-ref g 'items))))))
(displayln (jsexpr->string result))
(when (equal? result (list (hash 'o_orderpriority "1-URGENT" 'order_count 1) (hash 'o_orderpriority "2-HIGH" 'order_count 1))) (displayln "ok"))
