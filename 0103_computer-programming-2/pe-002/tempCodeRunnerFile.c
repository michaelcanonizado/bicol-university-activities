for (int i = 0; i < size; i++) {
        for (int j = 0; j < (size - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        
        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }