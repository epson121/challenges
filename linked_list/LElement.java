public class LElement{

	private int data;
	public LElement next;

	public LElement(int data){
		setData(data);
		setNext(null);
	}

	public void setData(int data){
		this.data = data;
	}

	public int getData(){
		return this.data;
	}

	public void setNext(LElement next){
		this.next = next;
	}

	public LElement getNext(){
		return this.next;
	}

	public void printElement(){
		System.out.println("Data is: " + this.data);
	}

}