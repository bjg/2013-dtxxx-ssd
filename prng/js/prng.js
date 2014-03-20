var P = 295075153;
var captured = [
    210205973,
    22795300,
    58776750,
    121262470,
    264731963,
    140842553,
    242590528,
    195244728,
    86752752
];

function Prng(x, y) {
    this.x = x;
    this.y = y;
}

Prng.prototype.nextPrng = function() {
    this.x = (2 * this.x + 5) % P;
    this.y = (3 * this.y + 7) % P;
    return this.x ^ this.y;
};

Prng.prototype.verify = function() {
    var q = new Prng(this.x, this.y);
    for (var k = 2; k < captured.length; k++) {
        if (captured[k] !== q.nextPrng()) {
            return false;
        }
    }
    console.log(q.nextPrng());
    return true;
};

var startTime = Date.now();
for (var x = 0; x < P; x++) {
    var p = new Prng(x, captured[0] ^ x);
    if (captured[1] === p.nextPrng() && p.verify()) {
        break;
    }
}
console.log(Date.now() - startTime, "ms");

