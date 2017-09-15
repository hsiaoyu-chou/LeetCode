select max(Salary)  as SecondHighestSalary from Employee
where Salary < (select max(Salary) from Employee) 

--find the max one which is smaller than the Max 