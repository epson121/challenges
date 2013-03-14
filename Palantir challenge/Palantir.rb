class Palantir

	def parse_expression(expr) 
		infix = ""
		expr = expr.split(" ")
		s = ["+", "-", "*"]
		expr.map do |e|
			if !s.include?(e)
				e = e.split("_")
				infix += convert_to_base_10(e[0], e[1])
			else
				infix += e
			end
		end
		#p convert_to_postfix(infix)
		p evaluate_postfix (convert_to_postfix(infix))
	end

	def convert_to_base_10(num, base)
		base_ = {"A" => 10, "B" => 11, "C" => 12, "D" => 13, "E" => 14, "F" => 15}
		result = 0
		i = 1
		num.split("").each do |char|
			if base.to_i < 10
				result += char.to_i * (base.to_i ** (num.length-i))
				i += 1
			else
				if base_.include?(char)
					result += base_[char] * (base.to_i ** (num.length-i))
				else
					result += char.to_i * (base.to_i ** (num.length-i))
				end
				i += 1
			end
		end
		result.to_s
	end

	def evaluate_postfix postfix
		result = 0
		stack = []
		postfix.split(" ").each do |char|
			if /^[0-9]/ === char
				stack.push(char)
			else
				n1 = stack.pop
				n2 = stack.pop
				case char
				when "+"
					result = n1.to_i + n2.to_i
				when "-"
					result = n2.to_i - n1.to_i
				when "*"
					result = n1.to_i * n2.to_i
				end
				stack.push(result)
			end
		end
		stack.pop
	end

	def precedence a
		prec = {"+" => 1, "-" => 1, "*" => 2}
		prec[a]
	end

	def convert_to_postfix infix
		stack = []
		postfix = ""
		infix.split("").each do |char|
			if /^[0-9]/ === char		#if char is a number
				postfix += char 		#add to postfix		
			else
				postfix += " "
				if stack.empty?
					stack.push(char)
				else
					while !stack.empty? && (precedence(stack.last) >= precedence(char))
						postfix += stack.pop
						postfix += " "
					end
					stack.push(char)
				end
			end
		end
		while !stack.empty?
			postfix += " "
			postfix += stack.pop
			postfix += " "
		end
		postfix
	end

end

#input = gets
#input = input.chomp

palantir = Palantir.new
palantir.parse_expression("12_10 + 111_2 + 1ABC_16")
palantir.parse_expression("12_10 + 111_2 * 11_10")
palantir.parse_expression("1430_5 - 110_2 * 2A_12 + 10_10")
