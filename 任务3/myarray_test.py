import myarray as mya
ma = mya.MyArray(1,2,3,4,5,6)
ma = ma * 2
print("ma 乘以 2 后：", ma)
mc = mya.MyArray(1,2,3,4,5,6)
result = ma * mc
print("ma 与 mc 的内积结果为：", result)