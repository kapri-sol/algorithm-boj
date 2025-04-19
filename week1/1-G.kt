fun match(reg: String, str: String): String {
    val (prefix, suffix) = reg.split("*")
    return if (str.length >= prefix.length + suffix.length &&
        str.startsWith(prefix) &&
        str.endsWith(suffix)
    ) "DA" else "NE"
}

fun main() {
    val num = readln().toInt()
    val reg = readln()
    val inputs = Array(num) { "" }
    for (i in 0 until num) {
        inputs[i] = readln()
    }
    inputs.forEach { println(match(reg, it)) }
}