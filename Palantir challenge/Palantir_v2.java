import java.util.*;
import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;

public class Palantir_v2{

	public Palantir_v2() {}

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
		
		ScriptEngineManager mgr = new ScriptEngineManager();
   	 	ScriptEngine engine = mgr.getEngineByName("JavaScript");
   	 	try{
    		System.out.println(engine.eval(infixDecimalExpression));
    	}
    	catch (Exception e){
    		System.out.println("Exception!");
    	}
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