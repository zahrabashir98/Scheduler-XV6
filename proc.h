// Per-CPU state
struct cpu {
  uchar apicid;                // Local APIC ID
  struct context *scheduler;   // swtch() here to enter scheduler
  struct taskstate ts;         // Used by x86 to find stack for interrupt
  struct segdesc gdt[NSEGS];   // x86 global descriptor table
  volatile uint started;       // Has the CPU started?
  int ncli;                    // Depth of pushcli nesting.
  int intena;                  // Were interrupts enabled before pushcli?
  struct proc *proc;           // The process running on this cpu or null
};

extern struct cpu cpus[NCPU];
extern int ncpu;

//PAGEBREAK: 17
// Saved registers for kernel context switches.
// Don't need to save all the segment registers (%cs, etc),
// because they are constant across kernel contexts.
// Don't need to save %eax, %ecx, %edx, because the
// x86 convention is that the caller has saved them.
// Contexts are stored at the bottom of the stack they
// describe; the stack pointer is the address of the context.
// The layout of the context matches the layout of the stack in swtch.S
// at the "Switch stacks" comment. Switch doesn't save eip explicitly,
// but it is on the stack and allocproc() manipulates it.
struct context {
  uint edi;
  uint esi;
  uint ebx;
  uint ebp;
  uint eip;
};

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// Per-process state
struct proc {
  uint sz;                     // Size of process memory (bytes)
  pde_t* pgdir;                // Page table
  char *kstack;                // Bottom of kernel stack for this process
  enum procstate state;        // Process state
  int pid;                     // Process ID
  struct proc *parent;         // Parent process
  struct trapframe *tf;        // Trap frame for current syscall
  struct context *context;     // swtch() here to run process
  void *chan;                  // If non-zero, sleeping on chan
  int killed;                  // If non-zero, have been killed
  struct file *ofile[NOFILE];  // Open files
  struct inode *cwd;           // Current directory
  char name[16];               // Process name (debugging)
  int ctime;
  float arrival_time;          //
};

// Process memory is laid out contiguously, low addresses first:
//   text
//   original data and bss
//   fixed-size stack
//   expandable heap


// int
// main(int argc, char *argv[]){
//   struct proc ptable[NPROC];
//   struct proc *p;
 

//   // err = getptable(NPROC * sizeof(struct proc), &ptable);
//   // if (err) {
//   //   printf(1,"Error getting ptable");
//   //   exit();
//   // }

//   // printf(1, "PID\t\tPPID\t\tSTATE\t\tPRIORITY\tTICKETS\t\tCPUTIME\t\tCMD\n");
//   for(p = ptable; p != &ptable[NPROC-1]; p++) {
//         // if (p->state == UNUSED) continue;
//     // printf(1, "sys_link : %d \n", p->ctime);

//     // printf (1, "%d",int(p->ctime));
// 	// init does not have ppid!
// 	// if (p->pid == 1)
// 	//     printf(1, "%d\t\tN/A",p->pid);
// 	// else
// 	//     printf(1, "%d\t\t%d", p->pid, p->ppid);

//   // 	switch(p->state){
//   // 	case UNUSED:
//   // 		printf(1,"\t\t%s", "UNUSED  ");
//   // 		break;
//   // 	case EMBRYO:
//   // 		printf(1,"\t\t%s", "EMBRYO  ");
//   // 		break;
//   // 	case SLEEPING:
//   // 		printf(1,"\t\t%s", "SLEEPING");
//   // 		break;
//   // 	case RUNNABLE:
//   // 		printf(1,"\t\t%s", "RUNNABLE");
//   // 		break;
//   // 	case RUNNING:
//   // 		printf(1,"\t\t%s", "RUNNING ");
//   // 		break;
//   // 	case ZOMBIE:
//   // 		printf(1,"\t\t%s", "ZOMBIE  ");
//   // 		break;
//   // 	}

//   //   printf(1, "\t%d", p->priority);
//   //   printf(1, "\t\t%d", p->tickets);
//     printf(1, "\t\t%d", p->ctime);
//   // 	printf(1,"\t\t%s\n", p->name);
//   }
//   exit();
// }
