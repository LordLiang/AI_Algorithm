function [] = mutation( pop_size,chromo_size,mutate_rate )
%mutation ����������
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
%mutate_rate: �������
global pop;
for i=1:pop_size
    if rand<mutate_rate
        mutate_pos=round(rand*chromo_size);%���ѡȡ����λ��
        if mutate_pos==0
            continue;
        end
        pop(i,mutate_pos)=1-pop(i,mutate_pos);
    end
end

clear i;
clear mutate_pos;
end

