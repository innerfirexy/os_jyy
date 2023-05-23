typedef struct {
  int pc, n;
  char from, to, via;
} Frame;

#define call(...) ({ *(++top) = (Frame) { .pc = 0, __VA_ARGS__ }; })
#define ret()     ({ top--; })
#define goto(loc) ({ f->pc = (loc) - 1; })
#define offset() ((int)(top - stk)/sizeof(Frame))
#define offset2() ((int)(top - stk))

void hanoi(int n, char from, char to, char via) {
  Frame stk[64], *top = stk - 1;

  printf("Initial stk=%p\n", stk);
  printf("Initial stk-1=%p\n", stk-1);
  printf("Initial &top=%p\n", top);
  //printf("Initial offset=%lu\n", offset());
  printf("Initial offset=%d\n", offset2());
  printf("Initial top->pc=%d, top->n=%d\n", top->pc, top->n);

  call(n, from, to, via);

  printf("After first call, top->pc= %d, top->n=%d, offset=%d\n", top->pc, top->n, offset2());

  int counter = 0;
  for (Frame *f; (f = top) >= stk; f->pc++) {
    n = f->n; from = f->from; to = f->to; via = f->via;
    switch (f->pc) {
      case 0: if (n == 1) { printf("%c -> %c\n", from, to); goto(4); } break;
      case 1: call(n - 1, from, via, to);   break;
      case 2: call(    1, from, to,  via);  break;
      case 3: call(n - 1, via,  to,  from); break;
      case 4: ret();                        break;
      default: assert(0);
    }
    printf("After step %d, f->pc=%d, f->n=%d, offset=%d\n", counter, f->pc, f->n, offset2());
    counter++;
  }
}
