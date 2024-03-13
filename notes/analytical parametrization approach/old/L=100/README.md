# What is wrong

In the experiments that are described here, there were those problems:

- We were missing a factor $0.5$ in the $C(t)$ expression when generating "fileCin.dat";
- We were looking for the expected asymptotic of $\log(1-u_k) v.s. \chi^2$ in the wrong region of values of $\chi^2$.

    This asymptotic is seen not so far from the kink's center. Thene there is another asymptotic, that is still linear, but has not the slope proportional to $\alpha^2$ (see new notes, with $L=10^3$ to see this clearly)
- The lattice is small compared to the duration of the experiment.
    So you can feel the effects of neighboring kinks overlapping.
    This has (at least) two consequences
    - You cannot consider anymore the kinks independent
    - The increase of the overlap, at least intuitively, leads to an increase in the distance between $\beta$ and $u(\frac34 L)$.
