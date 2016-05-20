function [] = rank( pop_size,chromo_size )
%rank 对个体按适应度大小进行排序，并且保存最佳个体
%pop_size: 种群大小
%chromo_size: 染色体长度
global fitness_value;%种群的适应度
global fitness_table;%种群累积适应度
global fitness_avg;
global best_fitness;
global best_individual;
global best_generation;
global pop;%当前代的种群基因
global G;%当前代的代数

for i=1:pop_size
    fitness_table(i)=0.;
end

key=1;
temp=1;
temp1(chromo_size)=0;
%按适应度递增排序
for i=1:pop_size
    key=i;
    for j=i+1:pop_size
        if fitness_value(j)<fitness_value(key);
            key=j;
        end
    end
    if key~=i
        temp=fitness_value(i);
        fitness_value(i)=fitness_value(key);
        fitness_value(key)=temp;
        for k=1:chromo_size
            temp1(k)=pop(i,k);
            pop(i,k)=pop(key,k);
            pop(key,k)=temp1(k);
        end
    end
end
figure(1);
subplot(1,2,1);
q=0.;
for i=1:pop_size
    for j=1:chromo_size
        if pop(i,j)==1
            q=q+2^(j-1);
        end
    end
    q=0.+q*(10.-0.)/(2^chromo_size-1);
    plot(q,fitness_value(i)-20,'.','markersize',6)%默认为6
end
    
%计算累积适应度
for i=1:pop_size
    if i==1
        fitness_table(i)=fitness_table(i)+fitness_value(i);
    else
        fitness_table(i)=fitness_table(i-1)+fitness_value(i);
    end
end
%计算平均适应度
fitness_avg(G)=fitness_table(pop_size)/pop_size;
%记录最好的个体
if fitness_value(pop_size)>best_fitness
    best_fitness=fitness_value(pop_size);
    best_generation=G;
    for j=1:chromo_size
        best_individual(j)=pop(pop_size,j);
    end
end

clear i;
clear j;
clear k;
clear min;
clear temp;
clear temp1;
end

    

