function [] = selection( pop_size,chromo_size,elitism )
%selection ���̶�ѡ�����
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
%cross_rate: �Ƿ�Ӣѡ��
global pop;%��ǰ������Ⱥ����
global pop_new;%��һ����Ⱥ
global fitness_table;%��Ⱥ�ۻ���Ӧ��

for i=1:pop_size
    r=rand*fitness_table(pop_size);%�������һ�����������0������Ӧ��֮��
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
%�Ƿ�Ӣѡ��
if elitism
    p=pop_size-1;%���Ǿ�Ӣѡ����ֻ��pop_newǰpop_size-1�����帳��pop,���һ��Ϊǰ�����Ÿ��屣��
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

