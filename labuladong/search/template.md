## 二分搜索

二分搜索框架代码:
```cpp
int left = 0, right = n;
while(left < right){
    int mid = left + (right - left) /2 ;
    if(nums[mid] < target){
        left = mid + 1;
    }else if(nums[mid] > target){
        right = mid;
    }else{
        left = mid;
    }
}
return left;
```

以上框架得到的left位置的值必然要大于等于target的值, 是target所在区间的右边