function [] = selection( pop_size,chromo_size,elitism )
%selection 轮盘赌选择操作
%pop_size: 种群大小
%chromo_size: 染色体长度
%cross_rate: 是否精英选择
global pop;%当前代的种群基因
global pop_new;%下一代种群
global fitness_table;%种群累积适应度

for i=1:pop_size
    r=rand*fitness_table(pop_size);%随机生成一个随机数，在0和总适应度之间
    first=1;
    last=pop_size;
    mid=round((last+first)/2);
    idx=-1;
    while(first<=last)&&(idx==-1)
        if r>fitness_table(mid)
            first=mid;
        else if r<fitness_table(mid)
                last=mid;
            else
                idx=mid;
                break;
            end
        end      
        mid=round((last+first)/2);
        if (last-first)==1
            idx=last;
            break;
        end
    end
    
    for j=1:chromo_size
        pop_new(i,j)=pop(idx,j);
    end
end
%是否精英选择
if elitism
    p=pop_size-1;%若是精英选择，则只将pop_new前pop_size-1个个体赋给pop,最后一个为前代最优个体保留
else
    p=pop_size;
end

for i=1:p
    for j=1:chromo_size
        pop(i,j)=pop_new(i,j);
    end
end


clear i;
clear j;
clear pop_new;
clear first;
clear last;
clear idx;
clear mid;

end

