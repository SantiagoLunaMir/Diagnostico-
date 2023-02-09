#include <stdio.h>
#include <stdlib.h>

void addAtTail(int array[],int *INITIAL_MAX_SIZE,int data);
int getAt(int array[],int index,int INITIAL_MAX_SIZE);
int size(int array[],int INITIAL_MAX_SIZE);
void removeAll(int array[],int INITIAL_MAX_SIZE);
void addAtFront(int array[],int *INITIAL_MAX_SIZE,int data);

int main(){
int INITIAL_MAX_SIZE=100;
int *array=(int*)malloc(INITIAL_MAX_SIZE*sizeof(int));

free(array);
}
/*
//addAtTail -> Inserta al final del arreglo
//addAtFront -> inserta al inicio del arreglo
//size -> Indica cuántos datos se han insertado 
//removeAll -> Borra todos los elementos insertados
//getAt -> Recibe un índice (0-index) y devuelve el valor en esa posición si es válido
*/
void addAtFront(int array[],int *INITIAL_MAX_SIZE,int data){
int i=0,j=0;
    while(array[i]!=NULL&&i<*INITIAL_MAX_SIZE){
        i++;
    }
    if(i>=*INITIAL_MAX_SIZE){
        *INITIAL_MAX_SIZE=(*INITIAL_MAX_SIZE*2);
        array=(int*)realloc(array,sizeof(int)*(*INITIAL_MAX_SIZE));
        while (array[j]!=NULL&&j<*INITIAL_MAX_SIZE){
            j++;
        }
        if(array[j]==NULL){
            int auxArray[j];
            i=0;
            while (array[i]!=NULL)
            {
                auxArray[i]=array[i];
                i++;
            }
            array[0]=data;
            j=0;
            while(auxArray[j]!=NULL){
                array[j+1]=auxArray[j];
                j++;
            }
            return;
        }
        int auxArray[i];
            i=0;
            while (array[i]!=NULL)
            {
                auxArray[i]=array[i];
                i++;
            }
            array[0]=data;
            j=0;
            while(auxArray[j]!=NULL){
                array[j+1]=auxArray[j];
                j++;
            }
            return;

    }
}
void addAtTail(int array[],int *INITIAL_MAX_SIZE,int data){
int i=0,j=0;
    while(array[i]!=NULL&&i<*INITIAL_MAX_SIZE){
        i++;
    }
    if(i>=*INITIAL_MAX_SIZE){
        *INITIAL_MAX_SIZE=(*INITIAL_MAX_SIZE*2);
        array=(int*)realloc(array,sizeof(int)*(*INITIAL_MAX_SIZE));
        while (array[j]!=NULL&&j<*INITIAL_MAX_SIZE){
            j++;
        }
        if (array[j]==NULL){
            array[j]=data;
        }
        return;
    }
    if(array[i]==NULL){
        array[i]=data;
        return;
    }
}
void removeAll(int array[],int INITIAL_MAX_SIZE){
    for(int i=0;i<INITIAL_MAX_SIZE;i++){
      array[i]=NULL;  
    }
    free(array);
}
int size(int array[],int INITIAL_MAX_SIZE){
    int i=0;
    while (array[i]!=NULL&&i<INITIAL_MAX_SIZE){
    i++;
    }
    return i;
}
int getAt(int array[],int index,int INITIAL_MAX_SIZE){
    if(index>=0&&index<=INITIAL_MAX_SIZE){
        return array[index];
    }
    return -1;
}