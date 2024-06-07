 #include <stdio.h>

int main(){

  int num = 15;
  int *pnum;
  pnum = &num;

  if (*pnum == num) printf("True|*pnum == %d; num == %d\n",*pnum,num); //*pnum == valor presente no endereco de pnumt
  if (pnum == &num) printf("True|pnum == %p; &num == %p\n",pnum,&num); //&num == endereco de num

  return 0;
}
