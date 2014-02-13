#!/usr/bin/env ruby

codes = []
ARGF.each_line do |line|
  if line =~ /^ [0-9a-f]+:\t([^\t]+)/
    $1.split(" ").each do |code|
      codes.push code
    end
  end
end
puts "\\x" + codes.join("\\x")
