<?php
ini_set('memory_limit', '-1');
$now_seed = 0;
$now_seeded = false;
$s = getenv('MOCHI_NOW_SEED');
if ($s !== false && $s !== '') {
    $now_seed = intval($s);
    $now_seeded = true;
}
function _now() {
    global $now_seed, $now_seeded;
    if ($now_seeded) {
        $now_seed = ($now_seed * 1664525 + 1013904223) % 2147483647;
        return $now_seed;
    }
    return hrtime(true);
}
$__start_mem = memory_get_usage();
$__start = _now();
  function f() {
  return [0, 0.0];
};
  function g($a, $b) {
  return 0;
};
  function h($s, $nums) {
};
  function main() {
  $ab = f();
  $a = $ab[0];
  $b = $ab[1];
  $cb = f()[1];
  $d = g($a, $cb);
  $e = g($d, $b);
  $i = g($d, 2.0);
  $list = [];
  $list = array_merge($list, [$a]);
  $list = array_merge($list, [$d]);
  $list = array_merge($list, [$e]);
  $list = array_merge($list, [$i]);
  $i = count($list);
};
  main();
$__end = _now();
$__end_mem = memory_get_usage();
$__duration = intdiv($__end - $__start, 1000);
$__mem_diff = max(0, $__end_mem - $__start_mem);
$__bench = ["duration_us" => $__duration, "memory_bytes" => $__mem_diff, "name" => "main"];
$__j = json_encode($__bench, 128);
$__j = str_replace("    ", "  ", $__j);
echo $__j, PHP_EOL;;
