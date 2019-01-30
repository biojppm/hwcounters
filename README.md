# hwcounters


## Platform notes

* Linux
  * Perf API
    * https://stackoverflow.com/questions/30293956/is-it-possible-to-use-linux-perf-profiler-inside-c-code
    * http://man7.org/linux/man-pages/man2/perf_event_open.2.html
  * SystemTap
    * https://stackoverflow.com/questions/30293956/is-it-possible-to-use-linux-perf-profiler-inside-c-code
    * https://sourceware.org/systemtap/

* Windows
  * https://randomascii.wordpress.com/2016/11/27/cpu-performance-counters-on-windows/
  * https://adamsitnik.com/Hardware-Counters-ETW/
  * https://docs.microsoft.com/en-us/windows/desktop/perfctrs/performance-counters-portal
```
% Processor Time
% User Time
% Privileged Time
Virtual Bytes Peak
Virtual Bytes
Page Faults/sec
Working Set Peak
Working Set
Page File Bytes Peak
Page File Bytes
Private Bytes
Thread Count
Priority Base
Elapsed Time
ID Process
Creating Process ID
Pool Paged Bytes
Pool Nonpaged Bytes
Handle Count
IO Read Operations/sec
IO Write Operations/sec
IO Data Operations/sec
IO Other Operations/sec
IO Read Bytes/sec
IO Write Bytes/sec
IO Data Bytes/sec
IO Other Bytes/sec
Working Set - Private
```


## Alternative apps/libs

* likwid (Linux only) https://github.com/RRZE-HPC/likwid
