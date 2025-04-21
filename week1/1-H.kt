fun main() {
    val (n, k) = readln().split(" ").map { it.toInt() }
    val temperatures = readln().split(" ").map { it.toInt() }
    val result = IntArray(n)

    var sum = temperatures.take(k).sum()
    var max = sum
    for(i in k until n) {
        sum += temperatures[i] - temperatures[i - k]
        max = maxOf(max, sum)
    }
    println(max)
}