void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int pivote(int data[], int s, int e){
    
    int pIndex = s + (e - s) / 2;
    int pValue = data[pIndex];
    swap(data + pIndex, data + e);
    int c = s;
    for(register int i = s; i < e; i++){
        if(pValue < data[i]){
            swap(data + i, data + c);
            c++;
        }
    }
    swap(data + c, data + e);
    return c;
}


void qsort(int data[], int s, int e){
    if(s < e){
        int p = pivote(data, s, e);
        qsort(data, s, p - 1);
        qsort(data, p + 1, e);
    }
}


int main(){

    int data[5] = {2, 5, 10, 8, 3};
    qsort(data, 0, 4);
    return 0;
}
