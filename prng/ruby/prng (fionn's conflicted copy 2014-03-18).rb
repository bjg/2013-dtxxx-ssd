#!/usr/bin/env ruby

P = 295075153
Captured = [
    210205973,
    22795300,
    58776750,
    121262470,
    264731963,
    140842553,
    242590528,
    195244728,
    86752752
]

class Prng
    def initialize(x, y)
        @x = x
        @y = y
    end

    def nextPrng()
        @x = (2 * @x + 5) % P
        @y = (3 * @y + 7) % P
        return @x ^ @y
    end

    def verify()
        t = Prng.new(@x, @y)
        puts t.inspect, t.nextPrng(), Captured[2]
        q = Prng.new(@x, @y)
        2.upto(Captured.length) do |k|
            return false if q.nextPrng() != Captured[k]
        end
        puts q.nextPrng()
        return true
    end
end


t = Time.now
0.upto(P) do |x|
    p = Prng.new(x, Captured[0] ^ x)
    break if p.nextPrng() == Captured[1] && p.verify()
end
puts "#{Time.now - t} seconds"
