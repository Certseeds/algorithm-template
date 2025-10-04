
# lab_05_B — Two Queues Ticket Office

## Description

SUSTech Cinema is open for business!

There are two ticket offices and all the students form two queues.

It takes each student one minute to buy his ticket(s).

The students can be separated into `n` groups each with one or two people.

To save time, two students in the same group will not queue up in the same line.

For the two-students group, if one group member has bought the tickets, the other one will leave the queue immediately.

Also, if two students get to the ticket windows at the same time, then they will buy their own ticket respectively.

Now LowbieH will give the description of the queueing situation, can you tell him the waiting time for each group?

## Input

The first line contains three integers `n, p, q (1 ≤ p, q ≤ n ≤ 100000)`, which are the number of groups and the lengths of the two queues.

The following two lines consist of serial numbers (range from `1` to `n`) in each queue separately.

Two same serial numbers stand for a two-people group.

## Output

Output the waiting time of each group in order.

## Sample Input

```log
5 4 5
1 2 3 4
2 4 1 3 5
```

## Sample Output

```log
1 1 2 2 3
```

## Idea

Simulate the process minute by minute: maintain two queues (arrays) storing group ids and process each minute by decrementing remaining people in front if present; record completion time per group.

Use arrays to track whether a group's member already bought the ticket so the other member leaves upon arrival.
