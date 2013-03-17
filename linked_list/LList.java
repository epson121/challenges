public class LList {

	LElement root;
	LElement pointer;
	LElement pointer_2;

	public LList(int data){
		root = new LElement(data);
	}

	public void insertLList(int data){
		pointer = root;
		while(pointer.getNext() != null){
			pointer = pointer.next;
		}
		LElement n = new LElement(data);
		pointer.setNext(n);
	}

	public void deleteLList(int data){
		pointer = root;
		pointer_2 = root;
		if (pointer.getData() == data){
			root = root.getNext();
			System.out.println("Deleted");
			return;
		}
		else {
			while(pointer_2.getNext() != null){
				pointer_2 = pointer_2.getNext();
				if (pointer_2.getData() == data){
					pointer.setNext(pointer_2.getNext());
					System.out.println("Deleted");
					return;
				}
				pointer = pointer.getNext();
			}
		}	
		if (pointer_2.getData() == data){
			pointer.setNext(null);
			System.out.println("Deleted");
			return;
		}
	}	

	public void printList(){
		System.out.println("List is: ");
		pointer = root;
		do{
			pointer.printElement();
			pointer = pointer.getNext();
		} while(pointer.getNext() != null);
		pointer.printElement();
	}

}