# Write your MySQL query statement below
# select p.firstname p.lastname a.city a.state from person as p,address as a
select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;