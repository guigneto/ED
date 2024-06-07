 #include <stdio.h>

int main(){

  int x;
  int *px;
  px = &x;
  scanf("%d",px);
  //ou
  scanf("%d",&*px);

  return 0;
}
