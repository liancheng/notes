########################
2013/09/25 VTune meeting
########################

Event Based Sampling

    不同事件统计方式不同：精确统计事件发生 v.s. Sampling

Parallelism/Concurrency analysis

    *   Profiling concurrency bottlenecks.
    *   线程间lock-and-wait等待关系分析（CAS指令也能覆盖？）
    *   通过Hook对各种可能block的函数（同步原语、IO等）插桩

Performance analysis methodology

    *   System

        BIOS, network IO, disk IO, ...

    *   Application

        Application design, algorithm tuning, ...

    *   Processor

        Cache/memory, instructions, SIMD, etc.

CPU前端可以并行issue 4个微指令（uops）

Instruction retired

Sandybridge Cache

    *   L1 cache (data + instruction)
    *   L2 per core
    *   L3 shared by cores (LLC)

CPI理想状况是0.25

.. rubric:: Misc.

*   `Intel Array Building Blocks`__
*   `Intel Parallel Building Blocks`__

.. http://en.wikipedia.org/wiki/Intel_Array_Building_Blocks
.. http://en.wikipedia.org/wiki/Intel_Parallel_Building_Blocks

*   EDRAM: above DRAM, below SRAM, shared by CPU and GPU
*   可以将内存中的指定区域映射为CPU和GPU共享，这部分内存中的数据可以进入LLC，从而提升CPU和GPU之间内存数据交换的速度
*   BPU: Branch Prediction Unit
