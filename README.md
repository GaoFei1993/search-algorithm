# 查找算法（search-algorithm） 
* 查找表是由同一类型的n个数据元素组成的集，对查找表的操作有四种：  
（1）在查找表中查找某数据；  
（2）在查找表中查找某数据的属性；  
（3）删除查找表中的某数据；  
（4）将某数据插入到查找表中。  
* 查找算法分为五大类，分别是顺序查找、二叉搜索、分块查找（索引查找）、二叉搜索树、哈希查找，如下图所示：  
![](http://images.cnitblog.com/blog/311549/201308/18162047-8570370e5d2741a0bf3441198c26b034.jpg)  

## 一、顺序查找  
* 基本思想：从查找表的第1个元素开始，顺序扫描，将扫描到的数据与给定数据key比较。若相等，则表示查找成功，返回当前数据的位置；若不相等，则继续顺序扫描，直到查找表的末端为止，始终未找到，则表示查找失败。  
* 复杂度：  
	* 时间复杂度：最坏情况下查找n次，故时间复杂度为O(n)  
	* 平均查找长度：（1+2+3+，，，+n）/n=（n+1）/2  

## 二、二叉搜索
### 1、二叉搜索  
* 基本思想：用给定值key先与中间结点(中间偏左)比较，从而分成了两个子表。若相等，则表示查找成功；若不相等，则根据key与中间结点的比较结果确定下一步查找哪个子表，递归进行，直到查找到key或者查找完查找表。  
* 查找公式：mid=low+(high-low)/2    
* 复杂度：  
	* 时间复杂度：最坏情况下查找log(n)+1次（logn向下取整），故时间复杂度为O(logn)  
	* 平均查找长度：若n无穷大，则为((n+1)log(n+1))/n–1；若n大于50，则为log(n+1)–1；否则按期望值计算（例如n=12时，（1\*1+2\*2+3\*4+4\*5）/12=3.1）。  

### 2、插值搜索  
* 基本思想：二叉搜索的改进版，二叉搜索始终搜索中间点，而插值搜索以给定值key在查找表的大致位置点将查找表分为两个表进行搜索（前提是查找表为均匀分布），属于自适应选择二分搜索点。  
* 查找公式：mid=low+(key-a[low])/(a[high]-a[low])\*(high-low)  
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

### 3、斐波那契搜索  
* 基本思想：二叉搜索的改进版，二叉搜索始终搜索中间点，而斐波那契搜索以查找表的黄金分割点将查找表分为两个表进行搜索。（前提是要将查找表扩充为Fibonacci[k]-1，该值为大于n且最接近n的斐波那契数列值）  
* 查找公式：mid=low+F(k-1)-1（比较的结果决定low和k的值）  
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

## 三、分块查找
* 基本思想：将n个数据元素"按块有序"划分为m块（m ≤ n），其中，每一块中的结点不必有序，但块与块之间必须"按块有序"。取各块的关键字最大值构成一个索引表，分别对应各块的地址。然后对索引表进行二叉搜索或顺序查找，先查找到给定值key属于哪一块。然后在块内进行顺序查找。  
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：分块查找的平均查找长度由两部分组成，一个是对索引表进行查找的平均查找长度，一个是对块内数据进行查找的平均查找长度。  
![](http://hi.csdn.net/attachment/201107/14/0_1310653444nsJA.gif)  

## 四、二叉搜索树
### 1、二叉搜索树  
* 基本思想：先让查找表的数据构成二叉树，确保二叉树的左分支的值小于右分支的值，然后再和每个节点的父节点比较大小，查找最适合的范围。  
* 二叉树的定义：
	* 1）若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；  
	* 2）若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；  
	* 3）任意节点的左、右子树也分别为二叉查找树。  
	* 4）没有键值相等的节点（no duplicate nodes）。  
* 复杂度：  
	* 时间复杂度：平均时间复杂度均为O(logn)，但是最坏情况下，时间复杂度为O(n)（因为插入和删除操作导致二叉树成为单支树）  
	* 平均查找长度：  
![Image text](http://github.com/GaoFei1993/search-algorithm/raw/master//BinaryTree.png) 

### 2、2-3树  
* 基本思想：
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

### 3、红黑树  
* 基本思想：
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

### 4、B树  
* 基本思想：
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

### 5、B+树  
* 基本思想：
* 复杂度：  
	* 时间复杂度：
	* 平均查找长度：  

## 五、哈希查找
* 基本思想：通过哈希函数，使关键字适度的分散到指定大小的的顺序结构中，越分散，则以后查找的时间复杂度越小，空间复杂度越高。首先用给定的哈希函数构造哈希表；然后根据选择的冲突处理方法解决地址冲突；最后在哈希表的基础上执行哈希查找。Hash查找其实是一种典型的以空间换时间的算法。（"直接定址"与"解决冲突"是哈希表的两大特点）  
* 复杂度：  
	* 时间复杂度：若没有内存限制，对于无冲突的Hash表而言，查找时间复杂度为O(1)。  
	* 平均查找长度：若没有内存限制，对于无冲突的Hash表而言，查找时间复杂度为O(1)。  
在正常情况下，哈希表会使用适度的时间和空间来进行查找，在这两个极端之间找到一个平衡点。  

## 总结
* 顺序查找：对查找表无要求。可以解决表元素动态变化的要求，但查找效率很低。  
* 二叉搜索：要求查找表是有序的，且是顺序存储的。难以满足查找表内的元素动态变化的要求。  
* 插值搜索：要求查找表是有序的，且是均匀分布的。  
* 斐波那契搜索：要求查找表是有序的。  
* 分块查找：要求索引表是有序的，对于块内的内容没有要求。对查找表的查找具有较快的速度，且查找表内的元素可动态变化。
* 二叉搜索树：  
* 2-3树：  
* 红黑树：  
* B树：  
* B+树：  
* 哈希查找：以空间换时间的方法，需要在时间和空间之间找到一个平衡点。  
