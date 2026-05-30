(ns main (:refer-clojure :exclude [connect main]))

(require 'clojure.set)

(defn in [x coll]
  (cond (string? coll) (clojure.string/includes? coll x) (map? coll) (contains? coll x) (sequential? coll) (some (fn [e] (= e x)) coll) :else false))

(def nowSeed (atom (let [s (System/getenv "MOCHI_NOW_SEED")] (if (and s (not (= s ""))) (Integer/parseInt s) 0))))

(declare connect main)

(defn connect [client]
  (try (throw (ex-info "return" {:v (and (not= (:Host client) "") (> (:Port client) 0))})) (catch clojure.lang.ExceptionInfo e (if (= (ex-message e) "return") (get (ex-data e) :v) (throw e)))))

(defn main []
  (do (def client {:Base "dc=example,dc=com" :Host "ldap.example.com" :Port 389 :UseSSL false :BindDN "uid=readonlyuser,ou=People,dc=example,dc=com" :BindPassword "readonlypassword" :UserFilter "(uid=%s)" :GroupFilter "(memberUid=%s)" :Attributes ["givenName" "sn" "mail" "uid"]}) (if (connect client) (println (str "Connected to " (:Host client))) (println "Failed to connect"))))

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
