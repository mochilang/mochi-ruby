{$mode objfpc}{$modeswitch nestedprocvars}
program Main;
uses SysUtils;
type IntArray = array of int64;
var _nowSeed: int64 = 0;
var _nowSeeded: boolean = false;
procedure init_now();
var s: string; v: int64;
begin
  s := GetEnvironmentVariable('MOCHI_NOW_SEED');
  if s <> '' then begin
    Val(s, v);
    _nowSeed := v;
    _nowSeeded := true;
  end;
end;
function _now(): integer;
begin
  if _nowSeeded then begin
    _nowSeed := (_nowSeed * 1664525 + 1013904223) mod 2147483647;
    _now := _nowSeed;
  end else begin
    _now := Integer(GetTickCount64()*1000);
  end;
end;
function _bench_now(): int64;
begin
  _bench_now := GetTickCount64()*1000;
end;
function _mem(): int64;
var h: TFPCHeapStatus;
begin
  h := GetFPCHeapStatus;
  _mem := h.CurrHeapUsed;
end;
procedure panic(msg: string);
begin
  writeln(msg);
  halt(1);
end;
procedure error(msg: string);
begin
  panic(msg);
end;
function _to_float(x: integer): real;
begin
  _to_float := x;
end;
function to_float(x: integer): real;
begin
  to_float := _to_float(x);
end;
procedure json(xs: array of real);
var i: integer;
begin
  write('[');
  for i := 0 to High(xs) do begin
    write(xs[i]);
    if i < High(xs) then write(', ');
  end;
  writeln(']');
end;
procedure json(x: int64);
begin
  writeln(x);
end;
procedure show_list_int64(xs: array of int64);
var i: integer;
begin
  write('[');
  for i := 0 to High(xs) do begin
    write(xs[i]);
    if i < High(xs) then write(' ');
  end;
  write(']');
end;
function list_int_to_str(xs: array of int64): string;
var i: integer;
begin
  Result := '[';
  for i := 0 to High(xs) do begin
    Result := Result + IntToStr(xs[i]);
    if i < High(xs) then Result := Result + ' ';
  end;
  Result := Result + ']';
end;
function list_list_int_to_str(xs: array of IntArray): string;
var i: integer;
begin
  Result := '[';
  for i := 0 to High(xs) do begin
    Result := Result + list_int_to_str(xs[i]);
    if i < High(xs) then Result := Result + ' ';
  end;
  Result := Result + ']';
end;
var
  bench_start_0: integer;
  bench_dur_0: integer;
  bench_mem_0: int64;
  bench_memdiff_0: int64;
function quick_sort(quick_sort_items: IntArray): IntArray; forward;
function quick_sort(quick_sort_items: IntArray): IntArray;
var
  quick_sort_pivot: int64;
  quick_sort_lesser: array of int64;
  quick_sort_greater: array of int64;
  quick_sort_i: int64;
  quick_sort_item: int64;
begin
  if Length(quick_sort_items) < 2 then begin
  exit(quick_sort_items);
end;
  quick_sort_pivot := quick_sort_items[0];
  quick_sort_lesser := [];
  quick_sort_greater := [];
  quick_sort_i := 1;
  while quick_sort_i < Length(quick_sort_items) do begin
  quick_sort_item := quick_sort_items[quick_sort_i];
  if quick_sort_item <= quick_sort_pivot then begin
  quick_sort_lesser := concat(quick_sort_lesser, IntArray([quick_sort_item]));
end else begin
  quick_sort_greater := concat(quick_sort_greater, IntArray([quick_sort_item]));
end;
  quick_sort_i := quick_sort_i + 1;
end;
  exit(concat(concat(quick_sort(quick_sort_lesser), IntArray([quick_sort_pivot])), quick_sort(quick_sort_greater)));
end;
begin
  init_now();
  bench_mem_0 := _mem();
  bench_start_0 := _bench_now();
  writeln('sorted1:', ' ', list_int_to_str(quick_sort([0, 5, 3, 2, 2])));
  writeln('sorted2:', ' ', list_int_to_str(quick_sort([])));
  writeln('sorted3:', ' ', list_int_to_str(quick_sort([-2, 5, 0, -45])));
  bench_memdiff_0 := _mem() - bench_mem_0;
  bench_dur_0 := (_bench_now() - bench_start_0) div 1000;
  writeln('{');
  writeln(('  "duration_us": ' + IntToStr(bench_dur_0)) + ',');
  writeln(('  "memory_bytes": ' + IntToStr(bench_memdiff_0)) + ',');
  writeln(('  "name": "' + 'main') + '"');
  writeln('}');
  writeln('');
end.
