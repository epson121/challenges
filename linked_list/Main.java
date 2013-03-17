public class Main{

	public static void main(String[] args){

		LList list = new LList(1);
		list.insertLList(2);
		list.insertLList(3);
		list.insertLList(4);
		list.insertLList(5);
		list.insertLList(6);
		list.printList();
		list.deleteLList(3);
		list.deleteLList(6);
		list.deleteLList(2);
		list.printList();
		list.insertLList(7);
		list.insertLList(8);
		list.printList();
		System.out.println(list.isEmpty());
		list.deleteLList(7);
		list.deleteLList(8);
		list.deleteLList(1);
		list.deleteLList(4);
		list.deleteLList(5);
		System.out.println(list.isEmpty());

	}
}