// Static variable
static int c;

int function_A(int p, int q)
{
  c = p + q;
  return c;
}

int main(int argc, char *argv[])
{
  // function local variable
  int a = function_A(1, 7);
  return a;
}
