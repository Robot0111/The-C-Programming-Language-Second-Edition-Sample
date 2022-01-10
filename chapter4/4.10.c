void qsort (int v[],int left,int right)
{
    int i,last;
    void swap(int v[],int i, int j);
    if (left >= right)
        return ;
    swap(v,left, (left + right)/2);
    last  = left;
    for(i = left +1; i <= right;i++)
        if(v[i] < v[left]){
            swap(v,++last,i);
        }
    swap(v,left,last);
    qsort(v,left,last - 1);
    qsort(v,last+1,right);
}
void swap(int v[],int i,int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(){
    int a[] ={8,5,7,2,0,6,9,3,1},i;
    qsort(a,0,8);
    for(i = 0; i < 9; i++ )
    printf("%d",a[i]);
};