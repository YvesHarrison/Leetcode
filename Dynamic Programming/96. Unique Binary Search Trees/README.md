1到n，n个数组成的不同的二叉搜索树，依次考虑i作为根节点生成的搜索树，i将1到n序列划分为2两部分，（1，i-1）和（i+1，n），（1，i-1）严格小于i只会出现在左子树，（i+1，n）严格大于i只会出现在右子树，考虑（1，i-1）和（i+1，n）能够生成多少种子树情况，既i-1个数组成的不同的二叉搜索树和n-i个数组成的不同的二叉搜索树，可以通过访问之前生成的动态规划数组获取，二者组合关系需相乘，