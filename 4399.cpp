int bin_find(int arr[], int arr_size, int num){

int low = 0;

int mid;

int high = arr_size - 1;

//二分查找过程

while(low <= high){

      mid = (low+high)/2;

      if(num == arr[mid]){

            return mid;

       }

      if(num > arr[mid]){

            low = mid + 1;

      }

      if(num < arr[mid]){

           high = mid - 1;

      }

  }

  return  -1;

}


