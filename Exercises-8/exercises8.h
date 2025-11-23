#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int key; // Assume keys are always unique.
struct Node *next; // Points to next node
struct Node *prev; // Points to previous node
} Node;

float** soru01(int M, int *Ns) {

    float **matris; // satırların adreslerinin yazılı olduğu bir listenin başını tutat
    
    matris = (float**) malloc(M*sizeof(float*));
    // malloc : M tane adres kağıdı sığacak kadar yer ver!
    // sizeof(float*) : Çünkü bu ana listede sayıları (float) değil, satırların adreslerini (pointer) saklayacağız. 
    // Pointer'lar hafızada float sayılardan farklı yer kaplar.

    if(matris == NULL) return NULL;

    for(int i = 0; i < M ; i++) {

        matris[i] = (float*) malloc(Ns[i]*sizeof(float));
    }
    return matris;
}


void soru02(float **A, int M) {

    for(int i = 0 ; i < M ; i++) {
        free(A[i]);
        A[i] = NULL;  // GÜVENLİK: Artık bu adrese erişilirse program çökmesin, NULL dönsün.
    }
    free(A); // 2. En son otel anahtarını (ana listeyi) iade et

    // NOT: Fonksiyon içinde 'A = NULL;' yapsak bile, bu sadece yerel kopyayı etkiler.
    // Main fonksiyonundaki asıl A değişkenini etkilemez (C'de pass-by-value vardır).
    // Ama el alışkanlığı olarak buraya da yazılabilir:
    // A = NULL; 
}


void soru03(float **A, int M, int *Ns) {

    for(int i = 0 ; i < M ; i++) {
        for(int j = 0 ; j < Ns[i] ; j++) {

            scanf("%f", &A[i][j]); // scanf adres ister "& işareti"
        }
    }
}

float* soru04(float **A, int M, int *Ns) {

    float *matris;
    matris = (float*) malloc(M*sizeof(float));

   
    for(int i = 0 ; i < M ; i++) {
        float sum = 0;
        for(int j = 0 ; j < Ns[i] ; j++) {
            sum += A[i][j]; 
        }
        matris[i] =(float) sum/Ns[i];
    }
    return matris;
}

float*** soru05(int M, int N, int K) {
    float ***matris;
    matris = (float***) malloc(M*sizeof(float**));

    for(int i = 0 ; i < M ; i++) {
        matris[i] = (float**) malloc(N*sizeof(float*));
        for(int j = 0 ; j < N ; j++) {
            matris[i][j] = (float*) malloc(K*sizeof(float));
        }
    }
    return matris;
}

void soru06(float ***A, int M ,int N,int K)  {

    // free sadece anahtar kabul eder eşya DEĞİL
    for(int i = 0 ; i < M ; i++) {
        for(int j = 0 ; j < N ; j++) {
            free(A[i][j]);
        }
        free(A[i]);
    }
    free(A);
}

void soru07(float ***A, int M, int N, int K) {

    for(int i = 0 ; i < M ; i++) {
        for(int j = 0 ; j < N ; j++) { 
            for(int q = 0 ; q < K ; q++) {
                scanf("%f", &A[i][j][q]);
            }
        } 
    }
}

float** soru08(float ***A, int M, int N, int K, int dim) {

// BAYA İYİ SORU
}

Node* soru09(Node *head, int key) {
    Node *current = head;

    while (current != NULL) {
        if(current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void soru10(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

int soru11(Node **headPtr, int key, int i) {
    
}