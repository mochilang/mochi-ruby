public class Main {
    static java.util.function.Supplier<Integer> fibNumber() {
        int[] a = new int[1];
        a[0] = 0;
        int[] b = new int[1];
        b[0] = 1;
        return () -> {
        int tmp = a[0] + b[0];
        a[0] = b[0];
        b[0] = tmp;
        return a[0];
};
    }

    static int fibSequence(int n) {
        java.util.function.Supplier<Integer> f = fibNumber();
        int r = 0;
        int i = 0;
        while (i < n) {
            r = ((Number)(f.get())).intValue();
            i = i + 1;
        }
        return r;
    }
    public static void main(String[] args) {
        {
            long _benchStart = _now();
            long _benchMem = _mem();
            long _benchDuration = _now() - _benchStart;
            long _benchMemory = _mem() - _benchMem;
            System.out.println("{");
            System.out.println("  \"duration_us\": " + _benchDuration + ",");
            System.out.println("  \"memory_bytes\": " + _benchMemory + ",");
            System.out.println("  \"name\": \"main\"");
            System.out.println("}");
            return;
        }
    }

    static boolean _nowSeeded = false;
    static int _nowSeed;
    static int _now() {
        if (!_nowSeeded) {
            String s = System.getenv("MOCHI_NOW_SEED");
            if (s != null && !s.isEmpty()) {
                try { _nowSeed = Integer.parseInt(s); _nowSeeded = true; } catch (Exception e) {}
            }
        }
        if (_nowSeeded) {
            _nowSeed = (int)((_nowSeed * 1664525L + 1013904223) % 2147483647);
            return _nowSeed;
        }
        return (int)(System.nanoTime() / 1000);
    }

    static long _mem() {
        Runtime rt = Runtime.getRuntime();
        rt.gc();
        return rt.totalMemory() - rt.freeMemory();
    }
}
