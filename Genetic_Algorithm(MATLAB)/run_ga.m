function [] = run_ga()
%run_ga 运行主函数

elitism = true;%选择精英操作
pop_size =50;%种群大小
chromo_size = 17;%染色体大小
generation_size = 200;%迭代次数
cross_rate = 0.6;%交叉概率
mutate_rate = 0.01;%变异概率

[m,n,p,q] = GeneticAlgorithm(pop_size, chromo_size, generation_size, cross_rate, mutate_rate,elitism);
disp "best individual"
m
disp "best fitness"
n
disp "x for best individual"
q
disp "generation number for best result"
p

clear;

end

