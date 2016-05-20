function [m,n,p,q] = GeneticAlgorithm( pop_size,chromo_size,generation_size ,cross_rate,mutate_rate,elitism)
%GeneticAlgorithm 主函数
%pop_size: 输入种群大小
%chromo_size: 输入染色体长度
%generation_size: 输入迭代次数
%cross_rate: 输入交叉概率
%mutate_rate: 输入变异概率
%elitism: 输入是否精英选择
%m: 输出最佳个体
%n: 输出最佳适应度
%p: 输出最佳个体出现的代数
%q: 输出最佳个体自变量值
global G;%当前代数
global fitness_value;%当前代适应度矩阵
global best_fitness;%历代最佳适应值
global fitness_avg;%历代平均适应值矩阵
global best_individual;%历代最佳个体
global best_generation;%最佳个体出现代

fitness_avg=zeros(generation_size,1);

figure(1);
width=1200;%宽度，像素数
height=500;%高度
left=200;%距屏幕左下角水平距离
bottem=100;%距屏幕左下角垂直距离
set(gcf,'position',[left,bottem,width,height])
subplot(1,2,1);
x=0:0.01:10;
y1=x+10*sin(5*x)+7*cos(4*x);
plot(x,y1);
grid on;
hold on;


fitness_value(pop_size)=0.;
best_fitness=0;
best_generation=0;
initilize(pop_size,chromo_size);
for G=1:generation_size
    fitness(pop_size,chromo_size);
    rank(pop_size,chromo_size);
    selection(pop_size,chromo_size,elitism);
    crossover(pop_size,chromo_size,cross_rate);
    mutation(pop_size,chromo_size,mutate_rate);
end

subplot(1,2,2);
plotGA(generation_size);
m=best_individual;
n=best_fitness-20;
p=best_generation;
q=0.;

for j=chromo_size-1:1
        best_individual(j)=xor(best_individual(j+1),best_individual(j)); %格雷码转二进制
end
for j=1:chromo_size
    if best_individual(j)==1
        q=q+2^(j-1);
    end
end
q=0.+q*(10.-0.)/(2^chromo_size-1);
subplot(1,2,1);
plot(q,n,'*r')%默认为6

save G;
save fitness_value;
save best_fitness;
save fitness_avg;
save best_individual;
save best_generation;

clear i;
clear j;
end

