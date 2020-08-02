## $prufer$ 序列

#### 1. 从无根树转化到 $prufer$ 序列

现在，给你一棵树，我们考虑如何把它变成 $prufer$ 序列。

我们需要重复进行以下操作，直至树中只剩下两个点：

1. 找到一个**度数为 $1$** 且**编号最小**的点。（其中编号最小保证了后面将会提到的 $prufer$ 序列的唯一对应性，同时也方便从 $prufer​ 序列转化回无根树）

2. 把这个点的父亲节点加入序列，然后把这个点从树中删除。

#### 2. 从 $prufer$ 序列转化到无根树

现在，给你一个 $prufer$ 序列，我们考虑如何把它变成一棵树。

我们需要重复进行以下操作，直至点集中只剩下两个点：（初始化所有点都在点集中）

1. 取出 $prufer$ 序列最前面的元素 $x$
2. 取出**在点集中**且**当前**不在 $prufer$ 序列中的最小元素 $y$。（这恰好呼应了前面提到过的选取编号最小的节点）
3. 在 $x,y$ 之间连一条边。（注意前面的取出相当于删除）

最后，我们在点集中剩下的两个点中连一条边。

显然这有 $n−1$ 条边，且绝对不会形成环，因此它是一棵树，且就是原树。

#### 3.  $prufer$ 序列的性质及相关结论

1. **$prufer$ 序列与无根树一一对应。**

2. **度数为 $d_i$ 的节点会在 $prufer$ 序列中出现 $d_i−1$ 次**

3. **一个 $n$ 个节点的有标号的无根树个数为 $n^{n−2}$**

   **一个 $n$ 个节点的有标号的有根树个数为 $n^{n−1}$**

4. **对于给定度数为 $d_{1∼n}$ 的一棵无根树共有 $\frac{(n-2)!}{\prod_{i=1}^{n}{(d_i-1)!}}$ 种情况**。



参考：

[初识prufer序列](https://www.cnblogs.com/chenxiaoran666/p/prufer.html)