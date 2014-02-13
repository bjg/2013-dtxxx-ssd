#!/usr/bin/env ruby

P = 295075153
captured = [210205973, 22795300, 58776750, 121262470, 264731963, 140842553, 242590528, 195244728, 86752752]

def nextPrng(x, y)
    x = (2 * x + 5) % P
    y = (3 * y + 7) % P
    return [x, y, (x ^ y)]
end

F = captured[0]
G = captured[1]
t = Time.now

0.upto(P) do |x|
    y = F ^ x
    x, y, z = nextPrng(x, y)
    if z == G
        x1, y1 = x, y
        z1 = nil

        2.upto(captured.length) do |k|
            x2, y2, z1 = nextPrng(x1, y1)
            break if z1 != captured[k]
            x1, y1 = x2, y2
        end

        if z1 == captured[captured.length-1]
            _, _, z2 = nextPrng(x1, y1)
            puts "#{captured[k]} ->  #{z2}"
            break
        end
    end
end
puts "#{Time.now - t} seconds"
