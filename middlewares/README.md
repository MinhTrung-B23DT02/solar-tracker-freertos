# Middlewares Directory

Thư mục này chứa mã nguồn FreeRTOS hoặc các thư viện middleware khác:
- **FreeRTOS-Kernel**:
  - `tasks.c`, `queue.c`, `list.c`, `timers.c`, `event_groups.c`
  - `include/`: Các file header của FreeRTOS (`FreeRTOS.h`, `task.h`, `queue.h`, ...)
  - `portable/`:
    - Port theo vi điều khiển (ví dụ: `GCC/ARM_CM4F`, `RVDS/ARM_CM3`, ...)
    - `MemMang/`: Quản lý bộ nhớ Heap (`heap_4.c`, ...)
