---
title: 漫画：什么是动态规划？ - 知乎
category: default
tags: 
  - zhuanlan.zhihu.com
created_at: 2020-09-27 09:11:56
original_url: https://zhuanlan.zhihu.com/p/31628866
---


# 漫画：什么是动态规划？ - 知乎

![](assets/1601169116-9a03c4ef75e1541eb044b853fb6c7f9d.jpg)

  

  

  

  

![](assets/1601169116-859087170c8488bf9d2f0055562d0bb1.jpg)

  

  

  

  

![](assets/1601169116-51434d02ef1d29a0c421ed37918516f0.jpg)

  

  

  

  

![](assets/1601169116-4d824663705dccdd35a5208dcda9fd8a.jpg)

  

  

  

————————————

  

  

  

  

![](assets/1601169116-d120354d34dbd7574741946ac92b6dab.jpg)

  

  

  

  

![](assets/1601169116-2d5d3ee03e6c3077213afae4eb36799d.jpg)

  

  

  

  

![](assets/1601169116-a755b020f454e459608ce5fcce0dd231.jpg)

  

  

  

**题目：**

  

有一座高度是**10**级台阶的楼梯，从下往上走，每跨一步只能向上**1**级或者**2**级台阶。要求用程序来求出一共有多少种走法。

  

比如，每次走1级台阶，一共走10步，这是其中一种走法。我们可以简写成 1,1,1,1,1,1,1,1,1,1。  

  

  

  

![](assets/1601169116-62f1f95306f21081c8e3009e5945dea0.jpg)

  

  

再比如，每次走2级台阶，一共走5步，这是另一种走法。我们可以简写成 2,2,2,2,2。

  

  

  

![](assets/1601169116-05772bec9e3e21de1afc83229f6f269a.jpg)

  

  

当然，除此之外，还有很多很多种走法。

  

  

  

![](assets/1601169116-471891df2b1052542a1ed8aa11583d74.jpg)

  

  

  

  

![](assets/1601169116-4cb8a21969486d4b2dd4455c3afebf4c.jpg)

  

  

  

  

![](assets/1601169116-2ffaeab88871e73df0d2ee57543b7721.jpg)

  

  

  

  

![](assets/1601169116-471891df2b1052542a1ed8aa11583d74.jpg)

  

  

  

  

![](assets/1601169116-e3f560bb2b3024443abdfff068e14091.jpg)

  

  

  

  

![](assets/1601169116-61fb291f13a159942c1a501c1ee1f729.jpg)

  

  

  

————————————

  

  

  

![](assets/1601169116-2f8c9ce8460aeedda31933d52f4f8282.jpg)

  

  

  

  

![](assets/1601169116-9589b6ce2b165c7c2586884d944a0900.jpg)

  

  

  

  

![](assets/1601169116-b67006f2cdc9055cfbac098d5a42948c.jpg)

  

  

  

  

![](assets/1601169116-451801129f0dc14546bc99f2390560ac.jpg)

  

  

  

  

![](assets/1601169116-7d3f5db03b3dc290f921fcfddb94f123.jpg)

  

  

  

  

![](assets/1601169116-49d3f8ff87aba08c27880ac0582d43ca.jpg)

  

  

  

  

![](assets/1601169116-925398725ed6d89e8fa6106507967214.jpg)

  

  

  

**第一种情况：**

  

  

  

![](assets/1601169116-9c09b202d262c9d30f10b42c71c5f941.jpg)

  

  

**第二种情况：**

  

  

  

![](assets/1601169116-1277e1a153fc601abb3151cdb54d0a7d.jpg)

  

  

  

  

![](assets/1601169116-3a5bbbb9fdc6ef4d4e3f2ec6346a7d7f.jpg)

  

  

  

  

![](assets/1601169116-03da742c334a5f040db86efbac23b1cb.jpg)

  

  

  

  

![](assets/1601169116-08b32f74bb25e6760ba43935df1ea0d5.jpg)

  

  

  

  

![](assets/1601169116-0514ad167e1a849e597a52e0a2fd9d4d.jpg)

  

  

  

  

![](assets/1601169116-16f89f0f0702b2d883df9c8b326375d6.jpg)

  

  

  

**把思路画出来，就是这样子：**

  

  

  

![](assets/1601169116-e19fc80d5e233a813ee20d90fafd131e.jpg)

  

  

  

  

![](assets/1601169116-a6720f486512044f32a48f780c313ad8.jpg)

  

  

  

  

![](assets/1601169116-106a73c85eba5ec840355517b9a2f87d.jpg)

  

  

  

  

![](assets/1601169116-6002e84b10be6ea2fa1c24d9cfaea613.jpg)

  

  

  

![](assets/1601169116-76d1ffd3ddbb755ba751b6c2def43719.jpg)

  

  

  

  

![](assets/1601169116-1cd67db3733906d96e97e257ac4b4f2c.jpg)

  

  

  

**F(1) = 1;**

**F(2) = 2;**

**F(n) = F(n-1)+F(n-2)（n>=3）**

  

  

  

![](assets/1601169116-7e5cb702f3f562712040eadf3e001355.jpg)

  

  

  

  

![](assets/1601169116-1c0e31fdb8533d621830aec8fdcf5ad9.jpg)

  

  

  

  

![](assets/1601169116-6d36a9167001137f783910101360d02f.jpg)

  

  

  

  

![](assets/1601169116-55eec7238fb725c50e1cfffa3d7e7a29.jpg)

  

  

  

  

![](assets/1601169116-eef141a70239b90e276099fe4ffefb16.jpg)

  

  

  

  

![](assets/1601169116-f171c55cb89ea2a40ee8f193247fabc4.jpg)

  

  

  

  

![](assets/1601169116-e7ed263eed2d616dfa4e9e6e44be938b.jpg)

  

  

  

  

![](assets/1601169116-277eae5c0f69347be32d00ee1ac09641.jpg)

  

  

  

  

![](assets/1601169116-0ec8d90f856cc206c09cf97664c63ec4.jpg)

  

  

  

**方法一：递归求解**

  

  

![](assets/1601169116-4a839e5c970185118f3fe443e2a881b0.jpg)

  

  

由于代码比较简单，这里就不做过多解释了。

  

  

  

![](assets/1601169116-89688642e69251fccf9fcf6743a51014.jpg)

  

  

  

  

![](assets/1601169116-4e832d5056a834901f0d8b9a64945011.jpg)

  

  

  

  

![](assets/1601169116-34d7110c0e3559a364a6531be6890623.jpg)

  

  

  

  

![](assets/1601169116-90da8a8859b4d4831b4bbadf18587476.jpg)

  

  

  

  

![](assets/1601169116-a8f27125290d56d705ad0676af778e29.jpg)

  

  

  

  

![](assets/1601169116-b5e6173455e48e64d0e8b94a70168279.jpg)

  

  

  

  

![](assets/1601169116-cb0254b6b7be14eb5c744e7dc6c3cb56.jpg)

  

  

  

  

![](assets/1601169116-7b1d3a06116a2a5152a9d6f27f4e8fdb.jpg)

  

  

  

  

![](assets/1601169116-cab489b4e7873456a5f06ea0e8c97d28.jpg)

  

  

  

  

![](assets/1601169116-973e67d3b07f8c1d3b22f31fabc4a37a.jpg)

  

  

  

  

![](assets/1601169116-72b427ab18f6f4698aebfc60d1707a1e.jpg)

  

  

  

  

![](assets/1601169116-49a0328793a3af56079d60a956b3476a.jpg)

  

  

  

如图所示，相同的颜色代表了方法被传入相同的参数。

  

  

  

![](assets/1601169116-41dee7c1d95b227950e1709b50eac37f.jpg)

  

  

  

  

![](assets/1601169116-cc3fe7ac5a7cc5a2617d3b1723b10287.jpg)

  

  

  

  

![](assets/1601169116-d43c2799969e9bd1647b91903b799fb5.jpg)

  

  

  

**方法二：备忘录算法**

  

  

![](assets/1601169116-f80c7f60100c2ea4796f955935102e3d.jpg)

  

  

在以上代码中，集合map是一个备忘录。当每次需要计算F(N)的时候，会首先从map中寻找匹配元素。如果map中存在，就直接返回结果，如果map中不存在，就计算出结果，存入备忘录中。

  

  

  

![](assets/1601169116-206471b9be59f3c14eed29458ab4ecca.jpg)

  

  

  

  

![](assets/1601169116-abcbdbd789a50e985ae0f6808d401e71.jpg)

  

  

  

  

![](assets/1601169116-f4f38afd428bcb7521db3b20d02274d5.jpg)

  

  

  

  

![](assets/1601169116-f94fde4ac4a3128ce143815808444786.jpg)

  

  

  

  

![](assets/1601169116-767819d2537cf04924258eb554140668.jpg)

  

  

  

  

![](assets/1601169116-09ae9cb5739b769512bfd8ef29690b99.jpg)

  

  

  

  

![](assets/1601169116-1faef158b2d82e9e30c85b965e07f1c5.jpg)

  

  

  

  

![](assets/1601169116-86d562ac33c7a1985e21ad1066bdbae6.jpg)

  

  

  

  

![](assets/1601169116-8c62e5ac65b9c65c74876050d2d5674b.jpg)

  

  

  

  

![](assets/1601169116-186730f2f0bc5f777f1fb0b1c4606bbb.jpg)

  

  

  

  

![](assets/1601169116-2fd97997cd02c6b8616a49aa2cdbd2dd.jpg)

  

  

  

  

![](assets/1601169116-2d649ddc5e12d142a1b2d8a26c9c3dc5.jpg)

  

  

  

  

![](assets/1601169116-91ded896aab7d07adee31dca5c904ed3.jpg)

  

  

  

  

![](assets/1601169116-542e53ba025749c0370cd7bb31a2db38.jpg)

  

  

  

  

![](assets/1601169116-ea717199138d9e18a9ebdeff1bcc4fa8.jpg)

  

  

  

  

![](assets/1601169116-55cc19c2878fb6db9632399fa2607cb7.jpg)

  

  

  

  

![](assets/1601169116-d618eb057fa2f8cca30aa386e4a1e0d0.jpg)

  

  

  

  

![](assets/1601169116-a943e3eceb9b4086c523891e2fded447.jpg)

  

  

  

  

![](assets/1601169116-a54715d3ca16360f6dc9826198536d78.jpg)

  

  

  

  

![](assets/1601169116-0fe2414c9a436bd27b3f5349965fe094.jpg)

  

  

  

  

![](assets/1601169116-04930da2f425a0260cee728f16883850.jpg)

  

  

  

  

![](assets/1601169116-4fc9a53045332ec4affdd114457cc94c.jpg)

  

  

  

**方法三：动态规划求解**

  

  

![](assets/1601169116-d7b54be9fb3884efb6fe972fb174be87.jpg)

  

  

程序从 i=3 开始迭代，一直到 i=n 结束。每一次迭代，都会计算出多一级台阶的走法数量。迭代过程中只需保留两个临时变量a和b，分别代表了上一次和上上次迭代的结果。 为了便于理解，我引入了temp变量。temp代表了当前迭代的结果值。

  

  

  

![](assets/1601169116-8563b3d474b7a67cc41d4302b6973de4.jpg)

  

  

  

  

![](assets/1601169116-f5805f80a003ff464752ea1c12f8c4d9.jpg)

  

  

  

  

![](assets/1601169116-ea303864601d2d219c0ad64b321f7acf.jpg)

  

  

  

  

![](assets/1601169116-388a477134f9c7e331cef029712dcac2.jpg)

  

  

  

  

![](assets/1601169116-8d9da9c0c0698aa9f93e51c093b5bf51.jpg)

  

  

  

  

![](assets/1601169116-1d6043c05dfe09cc8109e0d8e5581f17.jpg)

  

  

  

  

![](assets/1601169116-1970462f51fe545293a5f802fe41675e.jpg)

  

  

  

**题目二： 国王和金矿**

  

有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖，不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，应该选择挖取哪几座金矿？

  

  

  

![](assets/1601169116-ff62c840ceff2984e7792bb6b293e644.jpg)

  

  

  

  

![](assets/1601169116-e7ed263eed2d616dfa4e9e6e44be938b.jpg)

  

  

  

  

![](assets/1601169116-fe832690d6e9bd1857f21bc1ceeaee7e.jpg)

  

  

  

![](assets/1601169116-ed78cd74af997c623b3dfa89681347cf.jpg)

  

  

  

  

![](assets/1601169116-f16442f8a4df1923e2bdb0a3264ae704.jpg)

  

  

  

**方法一：排列组合**

  

每一座金矿都有挖与不挖两种选择，如果有N座金矿，排列组合起来就有2^N种选择。对所有可能性做遍历，排除那些使用工人数超过10的选择，在剩下的选择里找出获得金币数最多的选择。

  

代码比较简单就不展示了，时间复杂度也很明显，就是O(2^N)。

  

  

  

![](assets/1601169116-d4fe2caa24f04705036e92f9a51526a2.jpg)

  

  

  

  

![](assets/1601169116-c850bc26b19c8d40edf1d778b0982015.jpg)

  

  

  

  

![](assets/1601169116-7946ed12e5a13069ffa3654bfa509112.jpg)

  

  

  

  

![](assets/1601169116-90ec615cbc802f4d41b9d2b01c4bec44.jpg)

  

  

  

  

![](assets/1601169116-320e89e898e6acab1d7239396ce44401.jpg)

  

  

  

  

![](assets/1601169116-e4280c8fc90e26896f876aeb8a631dc0.jpg)

  

  

  

  

![](assets/1601169116-057c6f1ced9e32dd980f208fc78a1dfe.jpg)

  

  

  

  

![](assets/1601169116-5681e800cb0093617def6b98fadcd20d.jpg)

  

  

  

  

![](assets/1601169116-25be2dc6354f7396a9722398280d7a80.jpg)

  

  

  

  

![](assets/1601169116-89bc4c01781e189ebe74a6e00863ba22.jpg)

  

  

  

  

![](assets/1601169116-593c2306b52522bbdaa53d2060ee7607.jpg)

  

  

  

  

![](assets/1601169116-54de8dd3d56801408404518b56433fb0.jpg)

  

  

  

  

![](assets/1601169116-3ce80be083f09d9f2b14ff47f0924ef9.jpg)

  

  

  

  

![](assets/1601169116-be5ff127dd2b29e8f858a4966fe2779b.jpg)

  

  

  

  

![](assets/1601169116-5356be8d96a3f1d00206f0993b818f89.jpg)

  

  

  

  

![](assets/1601169116-2021b77e8063c3c4c101cf4353ed8563.jpg)

  

  

  

  

![](assets/1601169116-3527d4160975abdc09c04026ba03a01a.jpg)

  

  

  

  

![](assets/1601169116-cd8a7117c3de40bc429ca2955b09b8b4.jpg)

  

  

  

  

![](assets/1601169116-172f11de1523c05b1d617cb151dba076.jpg)

  

  

  

  

![](assets/1601169116-b17ff935b4ac8575bd817990f6359625.jpg)

  

  

  

  

![](assets/1601169116-67010982dcc8cc56658fc44ae78188d7.jpg)

  

  

  

**F(n,w) = 0 (n<=1, w<p\[0\]);**

  

**F(n,w) = g\[0\] (n==1, w>=p\[0\]);**

  

**F(n,w) = F(n-1,w) (n>1, w<p\[n-1\])**

  

**F(n,w) = max(F(n-1,w), F(n-1,w-p\[n-1\])+g\[n-1\]) (n>1, w>=p\[n-1\])**

  

其中第三条是补充上去的，原因不难理解。

  

  

  

![](assets/1601169116-283b39cc7de8a7fde1dfad33f8da90b5.jpg)

  

  

  

  

![](assets/1601169116-a14f0380e43e751aef66a7c6df29cf4e.jpg)

  

  

  

  

![](assets/1601169116-82d97836c266a7b230b02da22468766f.jpg)

  

  

  

**方法二：简单递归**

  

把状态转移方程式翻译成递归程序，递归的结束的条件就是方程式当中的边界。因为每个状态有两个最优子结构，所以递归的执行流程类似于一颗高度为N的二叉树。

  

方法的时间复杂度是O(2^N)。

  

  

**方法三：备忘录算法**

  

在简单递归的基础上增加一个HashMap备忘录，用来存储中间结果。HashMap的Key是一个包含金矿数N和工人数W的对象，Value是最优选择获得的黄金数。

  

方法的时间复杂度和空间复杂度相同，都等同于备忘录中不同Key的数量。

  

  

  

![](assets/1601169116-b625267fd1937df420b9cbd31b426274.jpg)

  

  

  

  

![](assets/1601169116-074c09045207e6f040c74d68b2df2a00.jpg)

  

  

  

  

![](assets/1601169116-47e83eae71ee9a00299933e94ed6c434.jpg)

  

  

  

  

![](assets/1601169116-990ee06033c205f11e1de2584cfeb6e9.jpg)

  

  

  

  

![](assets/1601169116-beee53fb548f3a499677963ac22146bd.jpg)

  

  

  

  

![](assets/1601169116-cdecfe1e958a095a69f506a639a28602.jpg)

  

  

  

  

![](assets/1601169116-1b4cca56dfad31f9b7757990b3695f91.jpg)

  

  

  

  

![](assets/1601169116-59a8f3a4d5c1a23494f26c69753a36a5.jpg)

  

  

  

  

![](assets/1601169116-cb5d21aa01f86261c495d26f09a2e227.jpg)

  

  

  

  

![](assets/1601169116-4a2be3071dd898cdfa392dcebb283e9f.jpg)

  

  

  

  

![](assets/1601169116-047acd554db7e89fc3b3ce0aeb27af0a.jpg)

  

  

  

  

![](assets/1601169116-39ff67d1d7ff02b1993586c8282de72a.jpg)

  

  

  

  

![](assets/1601169116-3cb080628e8c3a15d795320808fc122f.jpg)

  

  

  

  

![](assets/1601169116-98f3392c6260b439ccb913ea98b1de59.jpg)

  

  

  

  

![](assets/1601169116-c7f042ae951f27959fa95a4c7bdab356.jpg)

  

  

  

  

![](assets/1601169116-1a672db4bcfaa45f87c5c7e4f2c0a478.jpg)

  

  

  

  

![](assets/1601169116-dc095ea9a3b6091edf55bb53d368e6fc.jpg)

  

  

  

  

![](assets/1601169116-3effa3995586562104e012af42f1547e.jpg)

  

  

  

  

![](assets/1601169116-93b59101770af4e53d46bd34d56d204b.jpg)

  

  

  

  

![](assets/1601169116-eb375bdb1d9b778b2c2ccad5818be3de.jpg)

  

  

  

  

![](assets/1601169116-2041fc6e1bb4e16cc806f9295a6186b1.jpg)

  

  

  

  

![](assets/1601169116-f5da348feddb36191d92f5d59b4eb1a4.jpg)

  

  

  

  

![](assets/1601169116-2b5265b2cb55fd11201e5da588de7839.jpg)

  

  

  

  

![](assets/1601169116-2a4976c02eab26a2ab392e89959c7f88.jpg)

  

  

  

  

![](assets/1601169116-59460e052cc4b3d75f0de98dd21335cf.jpg)

  

  

  

  

![](assets/1601169116-605133fb7adcb54bda5a00d0c568d335.jpg)

  

  

  

  

![](assets/1601169116-cdb3049d8470ca77fa9ca53f9e6a1746.jpg)

  

  

  

**方法四：动态规划**

  

  

![](assets/1601169116-c6e0a84fd1d819082ddd4b98a9814e68.jpg)

  

  

方法利用两层迭代，来逐步推导出最终结果。在外层的每一次迭代，也就是对表格每一行的迭代过程中，都会保留上一行的结果数组 preResults，并循环计算当前行的结果数组results。

  

方法的时间复杂度是 O(n \* w)，空间复杂度是(w)。需要注意的是，当金矿只有5座的时候，动态规划的性能优势还没有体现出来。当金矿有10座，甚至更多的时候，动态规划就明显具备了优势。

  

  

  

![](assets/1601169116-cfe4515b38c874cdc50aa4f116b28a56.jpg)

  

  

  

  

![](assets/1601169116-c3aa6da9ab47e6530b6c73006015b97e.jpg)

  

  

  

  

![](assets/1601169116-eeb7b41f41efcf38980c0ce3e9c1287d.jpg)

  

  

  

  

![](assets/1601169116-0d3ed6cda5c14954bbae69bb1dc6c4d0.jpg)

  

  

  

  

![](assets/1601169116-3789cd94161524e879efa82e6e290e3c.jpg)

  

  

  

  

![](assets/1601169116-e57468f1ec82a4ca57314b17d31125cb.jpg)

  

  

  

  

![](assets/1601169116-4b2505b4f6790d5b6c0b16b563df4183.jpg)

  

  

  

  

![](assets/1601169116-507864101b9354fe2a3583d7db1042fb.jpg)

  

  

  

  

![](assets/1601169116-33e19126a4b7c97d0aeb4938508ece13.jpg)

  

  

  

![](assets/1601169116-4164834996d2598f664c5f95d161e96e.jpg)

  

  

  

  

![](assets/1601169116-8942cb3f008db0f90643f2b074d629da.jpg)

  

  

  

  

![](assets/1601169116-81e84e310604d674c7e9baf03f407aec.jpg)

  

  

  

  

![](assets/1601169116-972f46dc432fdb3ea39b97aeabb5f969.jpg)

  

  

  

  

![](assets/1601169116-0308b5d95282bccc3ef3b5ab46d4bbf9.jpg)

  

  

  

—————END—————

  

  

喜欢本文的朋友们，欢迎关注订阅号**程序员小灰**，收看更多精彩内容

  

**公众号名称： 程序员小灰**

**公众号ID： chengxuyuanxiaohui**

  

  

**本文为作者小灰原创作品，转载需经本人授权。**

---------------------------------------------------


原网址: [访问](https://zhuanlan.zhihu.com/p/31628866)

创建于: 2020-09-27 09:11:56

目录: default

标签: `zhuanlan.zhihu.com`

