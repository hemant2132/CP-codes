// mod operations
void mod(int &x,int p=M){ x%=p; x+=p; x%=p; }
int add(int a,int b,int p=M){ mod(a);mod(b); int c=a+b; if(c>=p) c-=p; return c; }
int sub(int a,int b,int p=M){ mod(a);mod(b); int c=a-b; if(c<0) c+=p; return c; }
int mul(int a,int b,int p=M){ mod(a);mod(b); int c=(a*1ll*b)%p; return c; }
