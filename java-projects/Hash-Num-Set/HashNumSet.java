package Main;
import Main.ListNode;

public class HashNumSet<E extends Number> implements NumSet<E>{
    private int capacity; 
    private int size; 
    private ListNode[] array; 

    public HashNumSet(int capacity){
        this.capacity = capacity;
        array = new ListNode[capacity];
    }

    private int hash(Number e, int range){
        int hashKey = e.hashCode();
        int key = hashKey % range;
        if (key < 0) {
            key += array.length;
        }
        return key;
    }

    @Override 
    public int capacity(){
        return capacity;
    }
    @Override
    public int size(){
        return size;
    }

    private void reSize(){
        ListNode[] tempArray = new ListNode[capacity * 2];
        int capacity1 = capacity * 2;
        for(int i = 0; i < array.length; i++){
            if(array[i] == null){
                continue;
            }
            ListNode temp = array[i];
            while(temp != null){
                ListNode addItem = new ListNode(temp.getItem());
                int key = hash(temp.getItem(), capacity1);
                
                if(tempArray[key] == null){
                    tempArray[key] = addItem;
                }
                else{
                    ListNode tempNew = tempArray[key];
                    while(tempNew.next != null){
                        tempNew = tempNew.next;
                    }
                    tempNew.next = addItem;
                }
                temp = temp.next;

            }
        }
        array = tempArray;
        capacity = capacity1;
    }

    @Override
    public boolean add(E e){
        if(e == null){
            throw new NullPointerException("Element is null"); // checks if parameter is null
        }
        if(size >= (array.length * 0.75)){
            reSize();
        }
        if(!contains(e)){
            Number x = e; 
            int key = hash(x, capacity);
            ListNode addItem = new ListNode(x);
            if(array[key] == null){
                array[key] = addItem;
                size++;
                return true;
            }
            ListNode temp = array[key];
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = addItem;
            size++;
            return true;
            

        }
        return false;
    }

    @Override
    public boolean remove(E e){
        if(e == null){
            throw new NullPointerException("Element is null"); // checks if parameter is null
        }
        if(contains(e)){
            Number x = e; 
            int key = hash(x, capacity);
            if(array[key].getItem().equals(x)){
                array[key] = array[key].next;
                size--;
                return true;
            }
            ListNode prev = array[key];
            ListNode temp = array[key];
            /* 
            if(temp.getItem() == x && prev.equals(temp)){
                array[key] = temp.next;
                size--;
                return true;
            }
            */
            temp = temp.next;
            while(temp != null){
                if(temp.getItem().equals(x) && temp.next == null){
                    prev.next = null;
                    size--;
                    return true;
                }
                else if(temp.getItem().equals(x)){
                    prev.next = temp.next;
                    size--;
                    return true;
                }
                prev = prev.next;
                temp = temp.next;

            }

        }
        return false;
    }

    @Override
    public boolean contains(E e){
        if(e == null){
            throw new NullPointerException("Element is null"); // checks if parameter is null
        }
        Number x = e; 
        int key = hash(x, capacity);
        ListNode temp = array[key];
        while(temp != null){
            if(temp.getItem().equals(x)){
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    public void print(){
        for(int i = 0; i < array.length; i++){
            System.out.print(i + " ");
            ListNode temp = array[i];
            while(temp != null){
                System.out.print((Number)temp.getItem() + " ");
                temp = temp.next;
            }
            System.out.println(" ");
        }
    }

    public static void main(String[] args){
        NumSet<Integer> numSet = new HashNumSet<>(10);
        numSet.add(210);
        numSet.add(90);
        numSet.add(95);
        numSet.add(170);
        numSet.add(171);
        System.out.println(numSet.remove(170));
    }


}
