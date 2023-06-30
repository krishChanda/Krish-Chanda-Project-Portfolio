package Main;

public class ListNode {
    public ListNode next;
    private final Number item;

    public ListNode(Number item) {
        this.item = item;
        this.next = null;
    }

    public Number getItem() {
        return this.item;
    }
}
