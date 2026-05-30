(ns main (:refer-clojure :exclude [mkAdd mysum partialSum main]))

(require 'clojure.set)

(defn in [x coll]
  (cond (string? coll) (clojure.string/includes? coll x) (map? coll) (contains? coll x) (sequential? coll) (some (fn [e] (= e x)) coll) :else false))

(defn padStart [s w p]
  (loop [out (str s)] (if (< (count out) w) (recur (str p out)) out)))

(def nowSeed (atom (let [s (System/getenv "MOCHI_NOW_SEED")] (if (and s (not (= s ""))) (Integer/parseInt s) 0))))

(declare mkAdd mysum partialSum main)

(declare main_add2 main_add3 main_partial)

(defn mkAdd [mkAdd_a]
  (try (throw (ex-info "return" {:v (fn [b] (+ mkAdd_a b))})) (catch clojure.lang.ExceptionInfo e (if (= (ex-message e) "return") (get (ex-data e) :v) (throw e)))))

(defn mysum [mysum_x mysum_y]
  (try (throw (ex-info "return" {:v (+ mysum_x mysum_y)})) (catch clojure.lang.ExceptionInfo e (if (= (ex-message e) "return") (get (ex-data e) :v) (throw e)))))

(defn partialSum [partialSum_x]
  (try (throw (ex-info "return" {:v (fn [y] (mysum partialSum_x y))})) (catch clojure.lang.ExceptionInfo e (if (= (ex-message e) "return") (get (ex-data e) :v) (throw e)))))

(defn main []
  (do (def main_add2 (mkAdd 2)) (def main_add3 (mkAdd 3)) (println (str (str (str (main_add2 5)) " ") (str (main_add3 6)))) (def main_partial (partialSum 13)) (println (str (main_partial 5)))))

(defn -main []
  (let [rt (Runtime/getRuntime)
    start-mem (- (.totalMemory rt) (.freeMemory rt))
    start (System/nanoTime)]
      (main)
      (System/gc)
      (let [end (System/nanoTime)
        end-mem (- (.totalMemory rt) (.freeMemory rt))
        duration-us (quot (- end start) 1000)
        memory-bytes (Math/abs ^long (- end-mem start-mem))]
        (println (str "{\n  \"duration_us\": " duration-us ",\n  \"memory_bytes\": " memory-bytes ",\n  \"name\": \"main\"\n}"))
      )
    ))

(-main)
