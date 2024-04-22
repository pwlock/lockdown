#include "pmount.h"
#include "power/input.h"
#include "power/ioctl.h"
#include <lockdown.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    asm volatile("xchg %bx, %bx");
    float i = 20.0f;
    i /= 2;

    WriteFile(0, "Hello!", 6);
    uint64_t t = IoControl(0, IOCTL_GET_INPUT_BUFFER, NULL, 0);
    void* pt = malloc(sizeof(struct input_event));
    while (ReadFile(t, pt, sizeof(struct input_event)) > 0) {
        WriteFile(0, "Event!", 6);
    }

    ptMountPartitions();
}
