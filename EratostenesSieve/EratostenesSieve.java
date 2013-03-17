// Eratstenes sieve, 01.02.2013.
// Author: Luka Rajcevic
// Java

public class EratostenesSieve{
	
	public static void main(String[] args){
		
		int i, j;
		int N = Integer.parseInt(args[0]);
		boolean[] isPrime = new boolean[N];
		for (i = 2; i < N; i++){
			isPrime[i] = true;
		}

		for (i = 2; i < N; i++){
			if(isPrime[i] == true){
				for(j = i; j * i < N; j++){
					isPrime[j*i] = false;
				}
			}
		}

		for (i = 2; i < N; i++){
			if (isPrime[i] == true){
				System.out.println(i);
			}
		}

	}

}