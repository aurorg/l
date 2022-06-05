import java.util.Collection;

public class TestmyBST {
    public static void main(String[] args){

    }
}


//接口
interface myTree<E>{
    //1.在BST中插入一个元素（新元素插在叶子结点处）
    boolean insert(E e);

    //2.在BST中查找一个元素（二分查找）
    boolean search(E e);

    //3.中序遍历
    void inorder();

    //4.后续遍历
    void postorder();

    //5.前序遍历
    void preorder();
}


//实现方法
class BST<E> implements myTree<E>{
    protected TreeNode<E> root;
    protected int size =0;
    protected java.util.Comparator<E> c;

    public BST(){
        this.c =(e1,e2) ->((Comparable<E>)e1).compareTo(e2);
    }

    public BST(java.util.Comparator<E> c){
        this.c=c;
    }

    public BST(E[] objects){
        this.c = (e1,e2) -> ((Comparable<E>)e1).compareTo(e2);
        for(int i=0;i<objects.length;i++){
           // add(objects[i]);
        }
    }

    //1.在BST中插入一个元素（新元素插在叶子结点处）
    //分两种情况
    //①这棵树是空的，使用新元素创建一个根结点
    //②这棵树不是空的，1》.寻找新元素结点的父结点的位置；为该元素创建一个新的结点，然后将该结点链接到它的父结点上
    //               2》 如果新元素小于父元素，则将新元素的结点设置为父结点的左子结点
    //               3》 如果新元素大于父元素，则将新元素的结点设置为父结点的右子结点
    @Override
    public boolean insert(E e){
        //如果这棵树是空的，使用新元素创建一个根结点
        if(root==null){
            root = createNewNode(e);
        }

        //寻找新元素结点的父结点的位置；为该元素创建一个新的结点，然后将该结点链接到它的父结点上
        else{
            TreeNode<E> parent = null;
            TreeNode<E> current = root; //创建一个新的结点

            while(current!=null){
                if(c.compare(e,current.element)<0){
                    parent = current;
                    current = current.left;
                }
                else if(c.compare(e,current.element)>0){
                    parent =current;
                    current = current.right;
                }
                else
                    return false;
            }

            //如果新元素小于父元素，则将新元素的结点设置为父结点的左子结点
            if(c.compare(e,parent.element)<0){
                parent.left = createNewNode(e);
            }
            //如果新元素大于父元素，则将新元素的结点设置为父结点的右子结点
            else{
                parent.right = createNewNode(e);
            }
        }
        size++;
        return true;
    }
    protected TreeNode<E> createNewNode(E e){
        return new TreeNode<>(e);
    }

    //2.在BST中查找一个元素（二分查找）
    @Override
    public boolean search(E e){
        //创建一个新的结点current，让current指向根结点
        TreeNode<E> current = root;

        //循环，直到current指向null，或者匹配到current.element
        while(current !=null){
            if(c.compare(e,current.element)<0){
                current =current.left;
            }
            else if(c.compare(e,current.element)>0){
                current = current.right;
            }
            else{
                return true;//表示找到了要查找的元素
            }
        }
        return false;//说明这个元素不在这棵树上
    }

    //****************中序遍历**************************************
    //递归的访问当前结点的左子树；然后访问当前结点；最后递归的访问该节点的右子树
    @Override
    public void inorder(){
        inorder(root);
    }

    protected void inorder(TreeNode<E> root){
        if(root ==null)
            return;
        inorder(root.left);
        System.out.print(root.element + "");
        inorder(root.right);
    }


    //*******************后序遍历***************************************
    //首先递归的访问当前结点的左子树，然后递归的访问该结点的右子树，最后访问结点本身
    @Override
    public void postorder(){
        postorder(root);
    }

    protected void postorder(TreeNode<E> root){
        if(root == null)
            return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.element + "");
    }


    //*******************前序遍历*********************************************
    //首先访问当前结点，然后递归的访问当前结点的左子树，最后递归的访问的访问当前结点的右子树
    @Override
    public void preorder(){
        preorder(root);
    }

    protected void preorder(TreeNode<E> root){
        if(root == null)
            return;
        System.out.print(root.element + "");
        preorder(root.left);
        preorder(root.right);
    }




}



//树结点
class TreeNode<E>{
    protected E element;
    protected TreeNode<E> left;
    protected TreeNode<E> right;

    public TreeNode(E e){
        element = e;
    }

}

