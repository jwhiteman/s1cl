def score(text)
  text.scan(/[etaoin shrdlu]/i).length
end

def decode(hex, key)
  hex.
    scan(/../).
    map do |byte|
      (byte.to_i(16) ^ key).chr
    end.join
end

max = 0
msg = ""
lin = -1
IO.read("4.txt").lines.each_with_index do |line, idx|
  0.upto(126) do |key|
    text  = decode(line, key)
    score = score(text)

    if score > max
      max = score
      msg = text
      lin = idx.succ
    end
  end
end

puts "#{msg.chomp} (#{lin})"
