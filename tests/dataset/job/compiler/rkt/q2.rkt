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

(define company_name (list (hash 'id 1 'country_code "[de]") (hash 'id 2 'country_code "[us]")))
(define keyword (list (hash 'id 1 'keyword "character-name-in-title") (hash 'id 2 'keyword "other")))
(define movie_companies (list (hash 'movie_id 100 'company_id 1) (hash 'movie_id 200 'company_id 2)))
(define movie_keyword (list (hash 'movie_id 100 'keyword_id 1) (hash 'movie_id 200 'keyword_id 2)))
(define title (list (hash 'id 100 'title "Der Film") (hash 'id 200 'title "Other Movie")))
(define titles (for*/list ([cn company_name] [mc movie_companies] [t title] [mk movie_keyword] [k keyword] #:when (and (equal? (hash-ref mc 'company_id) (hash-ref cn 'id)) (equal? (hash-ref mc 'movie_id) (hash-ref t 'id)) (equal? (hash-ref mk 'movie_id) (hash-ref t 'id)) (equal? (hash-ref mk 'keyword_id) (hash-ref k 'id)) (and (and (string=? (hash-ref cn 'country_code) "[de]") (string=? (hash-ref k 'keyword) "character-name-in-title")) (equal? (hash-ref mc 'movie_id) (hash-ref mk 'movie_id))))) (hash-ref t 'title)))
(define result (_min titles))
(displayln (jsexpr->string result))
(when (string=? result "Der Film") (displayln "ok"))
