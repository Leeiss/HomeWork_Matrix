## Произведение матриц со статичесим и динамическим выделением памяти  
### Задание
Реализовать умножение двух матриц типа int  
A[n][m]    
B[m][l]   
result[n][l]   
   
- Стандартный ввод cin
     
В вводе сначала идут 3 размерности n m l соответствующие   
A[n][m]  
B[m][l]    
result[n][l]  
Затем уже значения матриц
    
 - Стандартный вывод cout.
     
В выводе результирующая матрица (result) должна быть представлена в виде строк и столбцов 
    

______  
В execDynamic память для матриц выделяется динамически       
> Пример для функции execDynamic (для execStatic указать размерности вводом мы не можем, проверим вручную)
     
Input:    
3 4 2   
1 2 3 4  
5 6 7 8   
9	10 11	12   
13 14  
15 16  
17 18  
19 20  
   
Output:   
170	180  
426	452  
682	724  


В execStatic память для матриц выделяется статически 
> Для execStatic n m l задаются вручную  
  
Input:    
1 2 3 4  
5 6 7 8  
9	10 11	12  
13 14  
15 16  
17 18   
19 20  


  

 Output:  
170	180  
426	452  
682	724  
     
  между числами в строке используйте std::cout << ' ';  
 между строками используйте std::cout << std::endl;  
  
 
   
