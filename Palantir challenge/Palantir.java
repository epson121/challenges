import java.util.*;

public class Palantir{

	public Palantir() {}

	public void parseExpression(List<String> expr){
		String infixDecimalExpression = "";
		for (String str : expr){
			if (!str.equals("+") && !str.equals("*") && !str.equals("-")){
				String temp = convertToBase10(str);
				infixDecimalExpression += temp;
			}
			else{
				infixDecimalExpression += str;
			}
		}

		String postfix = convertToPostfix(infixDecimalExpression);
		System.out.println(postfix);
		System.out.println(evaluatePostfix(postfix));
	}

	private int evaluatePostfix(String postfix){
		int result = 0;
		Deque<Integer> s = new ArrayDeque<Integer>();
		String[] tokens = postfix.split(" ");
		for (int i = 0; i < tokens.length ; i++ ){
			if (!"+".equals(tokens[i]) && !"*".equals(tokens[i]) && !"-".equals(tokens[i])){
				//System.out.println("pushed to stack: " + tokens[i]);
				s.push(Integer.parseInt(tokens[i]));
			}
			else{
				int number1 = s.pop();
                int number2 = s.pop();
                //System.out.println("taken 2 numbers: " + number1 + " and " + number2);
                switch(tokens[i]) {
                    case "+":
	                    result = number1 + number2;
	                    break;
                    case "-":
	                    result = number2 - number1;
	                    break;
                    case "*":
	                    result = number1 * number2;
	                    break;  
                } 
                s.push(result);
                //System.out.println("pushed to stack result: " + result);
			}
		}
		return s.pop();
	}

	private int precedence(char e){
		if (e == '+' || e == '-')
			return 1;
		else
			return 2;
	}

	private String convertToPostfix(String infix){

		String postfix = "";
		Deque<Character> deque = new ArrayDeque<Character>();

		for (int i = 0; i < infix.length(); i++){
			if (Character.isDigit(infix.charAt(i))) {
				postfix += infix.charAt(i);
			}
			else{
				postfix += ' ';
				if (deque.isEmpty())
					deque.push(infix.charAt(i));
				else{
					while (!deque.isEmpty() && precedence(infix.charAt(i)) <= precedence(deque.peekFirst())) {
						postfix += deque.pop();
						postfix += ' ';
					}
					deque.push(infix.charAt(i));
				}
			}
		}

		while (deque.size() > 0){
			postfix += ' ';
			postfix += deque.pop();
			postfix += ' ';
		}
		return postfix;
	}

	private String convertToBase10(String num){
		int result = 0;
		String[] pNumber = num.split("_");
		String number = pNumber[0];
		int base = Integer.parseInt(pNumber[1]);
		for (int i = 0; i < number.length(); i++){
			result +=  Character.getNumericValue(number.charAt(number.length() - i - 1)) * Math.pow(base, i);
		}
		return "" + result;
	}

	public static void main(String[] args){
		List<String> tokens = new ArrayList<String>();
		Palantir p;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String expr = sc.next();
			tokens.add(expr);
		}
		p = new Palantir();
		p.parseExpression(tokens);
	}
}