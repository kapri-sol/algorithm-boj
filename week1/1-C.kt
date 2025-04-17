fun main() {
    val costs = readln().split(" ").map { it.toInt() } // cost[0] = A, cost[1] = B, cost[2] = C
    val times = IntArray(100)

    repeat(3) {
        val (start, end) = readln().split(" ").map { it.toInt() }
        for (i in start until end) {
            times[i - 1]++
        }
    }

    val totalCost = times.sumOf { it * costs.getOrElse(it - 1) { 0 } }

    println(totalCost)
}